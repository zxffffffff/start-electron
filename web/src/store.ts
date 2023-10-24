import { PayloadAction, configureStore, createSlice } from '@reduxjs/toolkit'
import { TypedUseSelectorHook, useDispatch, useSelector } from 'react-redux'

interface CounterState {
  value: number
}
export const counterSlice = createSlice({
  name: 'counter',
  initialState: {
    value: 0
  } as CounterState,
  reducers: {
    increment: state => {
      state.value += 1
    },
    decrement: state => {
      state.value -= 1
    },
    incrementByAmount: (state, action: PayloadAction<number>) => {
      state.value += action.payload
    }
  }
})
export const { increment, decrement, incrementByAmount } = counterSlice.actions
export const selectCount = (state: RootState) => state.counter.value

const store = configureStore({
  reducer: {
    counter: counterSlice.reducer
  }
})
export default store;

export type RootState = ReturnType<typeof store.getState>
export type AppDispatch = typeof store.dispatch

export const useAppDispatch: () => AppDispatch = useDispatch
export const useAppSelector: TypedUseSelectorHook<RootState> = useSelector

// demo
function how_to_set() {
  const dispatch = useAppDispatch();
  dispatch(increment())
  dispatch(incrementByAmount(123))
  dispatch(decrement())
}
function how_to_get() {
  const count = useAppSelector(selectCount);
  console.log(count);
}
