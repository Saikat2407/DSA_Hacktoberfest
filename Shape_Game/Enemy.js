function Enemy(x, y){
    this.x = x;
    this.y = y;
    
    this.speed;
    this.angle;
    this.size;
}

Enemy.prototype.spawn = ()=>{
    if(this.x && this.y){
            return;
    }else{
        let side = Math.round(Math.random() * 4)
        let randomSpot = Math.round(Math.random() * this.canvas.width)
        
        if(side === 0 || side === 4){
            this.x =  randomSpot;
            this.y = side === 0 ? this.size : this.canvas.width - this.size;
        }else 
        if(side === 1 || side === 3){
            this.x =  side === 1 ? this.size : this.canvas.width - this.size;
            this.y = randomSpot;
        }
    }
}
    

Enemy.prototype 
function fastCircleEnemy(x, y){
    Enemy.call(this, x , y)
    console.log(this.x, this.y)
    this.color = "blue";
    this.speed = 7;
    this.size = 20;
    this.angle = Math.random()*Math.PI*2;
    this.init = ()=>{
        {
            let side = Math.round(Math.random() * 4)
            let randomSpot = Math.round(Math.random() * canvas.width)
            
            if(side === 0 || side === 4){
                this.x =  randomSpot;
                this.y = side === 0 ? this.size : canvas.width - this.size;
            }else 
            if(side === 1 || side === 3){
                this.x =  side === 1 ? this.size : canvas.width - this.size;
                this.y = randomSpot;
            }
        }
    }
    this.init()
    this.move =  ()=>{
        this.x -=  this.speed/2 * Math.cos(this.angle+Math.PI/2)
        this.y -=  this.speed/2 * Math.sin(this.angle+Math.PI/2)
    }
    this.render = ()=>{
        ctx.beginPath()
        ctx.arc(this.x, this.y, this.size, 0, Math.PI * 2, true);
        ctx.fillStyle = this.color
        ctx.fill()
        ctx.closePath()
    }
    this.parallaxFunc = ()=>{
        let oldX = this.x;
        let oldY = this.y;

        this.x = this.x - 200 > canvas.width ? this.size / 2 : this.x;
        this.y = this.y - 200 > canvas.height ? this.size / 2 : this.y;
        this.x = this.x + 200 / 2 < 0 ? canvas.width - this.size : this.x;
        this.y = this.y + 200 / 2 < 0 ? canvas.height - this.size : this.y;
        if(oldX !== this.x || oldY!== this.y){
            let randomNumber = Math.random()/5
            this.angle += (1/10)-randomNumber;
        }
    }
}

fastCircleEnemy.prototype = new Enemy()
fastCircleEnemy.prototype.constructor = fastCircleEnemy


