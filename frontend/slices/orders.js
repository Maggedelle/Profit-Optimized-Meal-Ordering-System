import { createSlice, PayloadAction } from "@reduxjs/toolkit"

const orderSlice = createSlice({
    name: "order",
    initialState: {
        order: {
            id: null,
            pickUp: null,
            deliveryPoint: null,
            expectedDeliveryTime: null,
            state: null,
        }
    },
    reducers: {
        setOrder(state, action) {
            state.order.id = action.payload.id
        },
    }
})

export const { setOrder } = orderSlice.actions
export default orderSlice.reducer