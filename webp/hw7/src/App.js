import './App.css';
import login from './component/login';
import username from './component/username';
import password from './component/password';
import button from './component/button';

function App() {
  return (
    <div className = "App">
        <div className = 'login'> {login()} </div>
        <div className = 'info'> {username()} </div>
        <div className = 'info'> {password()} </div>
        <div className = 'button'> {button()} </div>
      </div>
  );
}

export default App;