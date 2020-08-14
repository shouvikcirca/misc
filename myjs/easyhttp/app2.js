const http = new EasyHTTP();


// http.get('https://jsonplaceholder.typicode.com/users')
// .then(data => console.log(data))
// .catch(err => console.log(err));


const data = {
    name:'Jack',
    username: 'jackfrost',
    email: '123@gmail.com'
}

// http.post('https://jsonplaceholder.typicode.com/users', data)
// .then(data => console.log(data))
// .catch(err => console.log(err));

http.delete('https://jsonplaceholder.typicode.com/users/9')
.then(data => {
    console.log(data);
})
.catch(err => console.log(err));

