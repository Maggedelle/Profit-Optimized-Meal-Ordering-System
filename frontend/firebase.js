// Import the functions you need from the SDKs you need
import firebase from 'firebase/compat/app';
import 'firebase/compat/auth';
import 'firebase/compat/firestore';
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
    apiKey: "AIzaSyBNM7-X_GiiteURmOFRUjK8m-oRdatbbYQ",
    authDomain: "p8-profit-optimized-ordering.firebaseapp.com",
    projectId: "p8-profit-optimized-ordering",
    storageBucket: "p8-profit-optimized-ordering.appspot.com",
    messagingSenderId: "334758812599",
    appId: "1:334758812599:web:3eadc6d664c34fe158a632",
    measurementId: "G-S1NNGSVE10"
};

// Initialize Firebase
let app;

if (firebase.apps.length === 0) {
    app = firebase.initializeApp(firebaseConfig)
} else {
    app = firebase.app();
}

const auth = firebase.auth();

export { auth };