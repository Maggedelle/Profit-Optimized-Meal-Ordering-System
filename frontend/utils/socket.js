import { REACT_APP_SOCKET_URL } from "@env";

export class WS {
  static init(userId) {
    const url = REACT_APP_SOCKET_URL;
    this.ws = new WebSocket(REACT_APP_SOCKET_URL + "/" + userId);
  }
  static onMessage(handler) {

    this.ws.addEventListener("message", handler);

  }

  static onOpen(handler) {

    this.ws.addEventListener("open", handler);

  }

  static onError(handler) {

    this.ws.addEventListener("error", handler);

  }

  static sendMessage(message) {
    // You can have some transformers here.
    // Object to JSON or something else...
    try {

      this.ws.send(message);
    } catch (error) {
      alert(error)
    }
  }
}
