from fastapi import FastAPI, Form
from fastapi.responses import PlainTextResponse
import uvicorn


def main():
    app = FastAPI()

    # Обрабатываем GET-запрос (проверка связи)
    @app.get("/ping")
    def ping():
        # Возвращаем статус 200 OK автоматически
        return {"status": "alive"}

    # Обрабатываем POST-запрос (прием сообщения)
    # В C++ мы использовали cpr::Payload, поэтому здесь ждем данные из Form
    @app.post("/message", response_class=PlainTextResponse)
    def receive_message(text: str = Form(...)):
        print(f"\n[+] Получено сообщение от C++ программы: {text}\n")

        # Этот текст вернется в C++ как r.text
        return f"Привет, C++! Бот успешно получил твое сообщение: '{text}'"

    uvicorn.run(app, host="127.0.0.1", port=8000)


if __name__ == "__main__":
    main()
