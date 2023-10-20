import React, { useState } from 'react';
import logo from './logo.svg';
import './App.css';
import IpcBridge from './platform/electron-bridge';

function MyButton() {
  const [count, setCount] = useState(0);

  async function handleClick() {
    let ret = '';
    if (count === 0)
      ret = await IpcBridge.Call('Init');
    else
      ret = await IpcBridge.Call('Func');
    console.log(ret)
    setCount(count + 1);
  }

  return (
    <button onClick={handleClick}>
      Clicked {count} times
    </button>
  );
}

function App() {
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.tsx</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
        <MyButton />
      </header>
    </div>
  );
}

export default App;
