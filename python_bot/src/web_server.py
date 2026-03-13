from fastapi import FastAPI, Form


class WebServer:
    def __init__(self, bot=None):
        self.app = FastAPI()
        self.bot = bot
        self._setup_routes()

    def _setup_routes(self):
        @self.app.get("/ping")
        async def ping():
            return {"status": "alive"}

        @self.app.post("/message")
        async def receive_message(text: str = Form(...)):
            return {"status": "Message handed over to bot"}

