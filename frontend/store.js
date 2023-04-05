import { configureStore } from '@reduxjs/toolkit';
import orderReducer from './slices/orders';

export const store = configureStore({
    reducer: {
        order: orderReducer
    }
});