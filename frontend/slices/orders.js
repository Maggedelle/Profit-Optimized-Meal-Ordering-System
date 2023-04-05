import { createSlice, PayloadAction } from "@reduxjs/toolkit"

const orderSlice = createSlice({
    name: "order",
    initialState: {
        order: {
            id: null,
            pickUp: null,
            deliveryPoint: null,
            expectedDeliveryTime: null,
            distance: null,
            state: null,
        }
    },
    reducers: {
        setOrder(state, action) {
            state.order.id = action.payload.id
            state.order.pickUp = action.payload.pickUp
            state.order.deliveryPoint = action.payload.deliveryPoint
            state.order.expectedDeliveryTime = action.payload.expectedDeliveryTime
            state.order.distance = action.payload.distance
            state.order.state = "pending"
        },
        setOrderState(state, action) {
            state.order.state = action.payload
        }
    }
})

export const { setOrder, setOrderState } = orderSlice.actions
export default orderSlice.reducer