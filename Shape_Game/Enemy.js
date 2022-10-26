function Enemy(canvas, ctx, x, y){
    this.x = x;
    this.y = y;
    this.canvas = canvas;
    this.ctx = ctx;
    
    this.speed;
    this.angle;
    this.size;

    
        
    

    this.parallaxFunc = ()=>{
        this.x = this.x + this.size > this.canvas.width ? this.size / 2 : this.x;
        this.y = this.y + this.size > this.canvas.height ? this.size / 2 : this.y;
        this.x = this.x - this.size / 2 < 0 ? this.canvas.width - this.size : this.x;
        this.y = this.y - this.size / 2 < 0 ? this.canvas.height - this.size : this.y;
    }

    this.spawn =  ()=>{
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
}