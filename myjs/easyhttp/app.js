const http = new easyhttp();


// Get Posts
// http.get('https://jsonplaceholder.typicode.com/posts', function(err, response)
// {
//     if(err)
//     {   
//         console.log(err);
//     }
//     else
//     {
//         console.log(response);
//     }
// });


// Get Single Post
// http.get('https://jsonplaceholder.typicode.com/posts/1', function(err, response)
// {
//     if(err)
//     {   
//         console.log(err);
//     }
//     else
//     {
//         console.log(response);
//     }
// });



// Create Data
const data = {
    title:'Custom Post',
    body:'This is a custom post'
};

//Create post
// http.post('https://jsonplaceholder.typicode.com/posts', data, function(err, post)
// {
//     if(err)
//     {
//         console.log(err);
//     }
//     else
//     {
//         console.log(post);
//     }

// })


// Using PUT to update object with id5 in given api with our data object 
// http.put('https://jsonplaceholder.typicode.com/posts/5', data, function(err, post)
// {
//     if(err)
//     {
//         console.log(err);
//     }
//     else
//     {
//         console.log(post);
//     }

// });


// Using DELETE
http.delete('https://jsonplaceholder.typicode.com/posts/1', function(err, response)
{
    if(err)
    {   
        console.log(err);
    }
    else
    {
        console.log(response);
        console.log('Post deleted')
    }
});















