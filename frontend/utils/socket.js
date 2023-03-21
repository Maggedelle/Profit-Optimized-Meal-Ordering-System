

import { REACT_APP_SOCKET_URL } from "@env";

var ws = new WebSocket(REACT_APP_SOCKET_URL);
export default function Socket() {

    ws.onopen = () => {
        console.log("Connected to socket server")
    };

    ws.onmessage = (e) => {
        console.log("Recieved Message");
    }

    ws.onerror = (e) => {
        // an error occurred
        alert(e.message + ": Please restart app.");
    };

}
export function sendMessage(message) {
    ws.send(message);
}