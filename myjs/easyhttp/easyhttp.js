function easyhttp()
{
    this.http = new XMLHttpRequest();
}

//Make an HTTP GET Request
easyhttp.prototype.get = function(url, callback)
{
        this.http.open('GET',url, true);

        // ES6 arrow functions solves the scoping problem with 'this' for http.status
        // In ES5 the following is done

    let self = this;
    this.http.onload = function() 
    {
        if(self.http.status === 200)
        {
            callback(null, self.http.responseText); 
        }
        else
        {
            callback('Error '+self.http.status);
        }
    }
    this.http.send();
}



//Make an HTTP POST Request
easyhttp.prototype.post = function(url, data, callback)
{
    this.http.open('POST',url, true);

    this.http.setRequestHeader('Content-type', 'application/json');
    let self = this;
    this.http.onload = function() 
    {
        callback(null, self.http.responseText); 
        
    }

    this.http.send(JSON.stringify(data));

}




//Make an HTTP PUT Request
easyhttp.prototype.put = function(url, data, callback)
{
    this.http.open('PUT',url, true);

    this.http.setRequestHeader('Content-type', 'application/json');
    let self = this;
    this.http.onload = function() 
    {
        callback(null, self.http.responseText); 
        
    }

    this.http.send(JSON.stringify(data));

}





//Make an HTTP DELETE Request
easyhttp.prototype.delete = function(url, callback)
{
        this.http.open('DELETE',url, true);

        // ES6 arrow functions solves the scoping problem with 'this' for http.status
        // In ES5 the following is done

        let self = this;
        this.http.onload = function() 
        {
            if(self.http.status === 200)
            {
                // Response will be an empty object because we are deleting a post
                callback(null, self.http.responseText); 
            }
            else
            {
                callback('Error '+self.http.status);
            }
        }
        this.http.send();
}