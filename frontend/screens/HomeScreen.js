import { StyleSheet, Text, TouchableOpacity, View } from 'react-native'
import React from 'react'
import { auth } from '../firebase'
import { useNavigation } from '@react-navigation/native'
export default function HomeScreen() {

    const navigation = useNavigation();
    const handleSignOut = () => {
        auth.signOut()
            .then(() => {
                navigation.replace("Login");
            })
            .catch(error => alert(error.message))
    }

    const lol = () => {
        console.log("haha")
    }

    return (
        <View>
            <Text>Welcome {auth.currentUser.email}</Text>

            <TouchableOpacity onPress={handleSignOut}>
                <Text>Sign out</Text>
            </TouchableOpacity>
        </View>
    )
}

const styles = StyleSheet.create({})