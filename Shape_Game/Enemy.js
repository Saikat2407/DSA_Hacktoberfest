const fastCircleEnemy = {speed: 7, size: 15, color: "blue"}
const regularEnemy = {speed: 3, size: 20, color: "red"}


function Enemy({speed, size, color}){
    this.color = color;
    this.speed = speed;
    this.size = size;
    this.angle = Math.random()*Math.PI*2;
    this.init = ()=>{
        {
            let side = Math.round(Math.random() * 3)
            let randomSpot = Math.round(Math.random() * canvas.width)
            
            if(side === 0 || side === 2){
                this.x =  randomSpot;
                this.y = side === 0 ? this.size : canvas.width - this.size;
            }else 
            if(side === 1 || side === 3){
                this.x =  side === 1 ? this.size : canvas.width - this.size;
                this.y = randomSpot;
            }
            console.log(side, this.x, this.y, this)
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

        this.x = this.x - 150 > canvas.width ? this.size / 2 : this.x;
        this.y = this.y - 150 > canvas.height ? this.size / 2 : this.y;
        this.x = this.x + 150 / 2 < 0 ? canvas.width - this.size : this.x;
        this.y = this.y + 150 / 2 < 0 ? canvas.height - this.size : this.y;
        if(oldX !== this.x || oldY!== this.y){
            let randomNumber = Math.random()/5
            this.angle += (1/10)-randomNumber;
        }
    }
}




