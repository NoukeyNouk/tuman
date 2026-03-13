import asyncio
import uvicorn
from web_server import WebServer
# Не забудь добавить aiogram и uvicorn в зависимости твоего pyproject.toml

async def async_main():
    web_server = WebServer()
    
    # Настраиваем Uvicorn
    config = uvicorn.Config(app=web_server.app, host="0.0.0.0", port=8000)
    server = uvicorn.Server(config)

    print("Запускаем сервер и бота...")
    
    # Запускаем обе корутины конкурентно в одном event loop
    await asyncio.gather(server.serve())


def main():
    try:
        asyncio.run(async_main())
    except KeyboardInterrupt:
        print("\nПрограмма остановлена вручную.")


if __name__ == "__main__":
    main()
