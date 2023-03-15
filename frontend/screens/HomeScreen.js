import { StyleSheet, Text, TouchableOpacity, View } from 'react-native'
import React from 'react'
import { auth } from '../firebase'
import { useNavigation } from '@react-navigation/native'
import { REACT_APP_API_URL } from "@env";
export default function HomeScreen() {

    const navigation = useNavigation();
    const handleSignOut = () => {
        auth.signOut()
            .then(() => {
                navigation.replace("Landing");
            })
            .catch(error => alert(error.message))
    }

    const sendRequest = () => {
        fetch(REACT_APP_API_URL + '/worker/state', {
            method: 'POST',
            headers: {
                Acccept: 'application/json',
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({
                someParam: "Test"
            })
        }).then(json => {
            console.log(json)
        }).catch(error => {
            alert(error);
        })
    }

    return (
        <View>
            <Text>Welcome {auth.currentUser.email}</Text>
            <TouchableOpacity onPress={sendRequest}>
                <Text>Send Request</Text>
            </TouchableOpacity>
            <TouchableOpacity onPress={handleSignOut}>
                <Text>Sign out</Text>
            </TouchableOpacity>
        </View>
    )
}

const styles = StyleSheet.create({})