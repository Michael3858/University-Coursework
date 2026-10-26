import Button from '@mui/material/Button';
import TextField from '@mui/material/TextField';
import FormControlLabel from '@mui/material/FormControlLabel';
import Checkbox from '@mui/material/Checkbox';
import CardActions from '@mui/material/CardActions';

const Login = () => {
    return (
        <div>
            <h2>Sign in CSIE@CGU</h2><br />
            <TextField label="Email Address" variant="outlined" required></TextField><br /><br />
            <TextField label="Password" type="password" variant="outlined" required></TextField><br /><br />
            <FormControlLabel control={<Checkbox defaultChecked />} label="Remember me" /><br /><br />
            <Button variant="contained">SIGN IN</Button><br /><br />
            <CardActions>
                <Button size="small" color="primary">
                    Forgat password?
                </Button>
                <Button size="small" color="primary">
                    Don't have an account?
                </Button>
                <Button size="small" color="primary">
                    Sign Up
                </Button>
            </CardActions>
        </div>
    );
}

export default Login;