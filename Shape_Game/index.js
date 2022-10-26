function Game(){
    this.player = null;
    this.canvas
    this.ctx
    this.mouse = {onCanvas:false, position: {x: -1, y: -1}}
    this.bullets = [];
    this.enemies = []

    this.newContainer = ()=>{
        document.body.innerHTML = "<canvas id=\"view\" style=\" background: #eeeeee;display:flex; justify-content:center; \"><canvas>"
        
    }
    
    this.start = ()=>{
        this.newContainer()
        this.canvas = document.getElementById('view');
        this.canvas.width =  500;
        this.canvas.height =  500;
        this.ctx = this.canvas.getContext('2d');

        this.player =  new Player(this.ctx, this.canvas, this.mouse);
        this.player.create(0, 0, 10, "red")
        
        this.draw()
       
    }

   this.draw = ()=>{
        // console.log(Math.atan(3/2)* 180/Math.PI)
        window.scrollTo(this.player.x- $(window).width()/2+100,this.player.y- $(window).height()/2+100)
        // console.log(theScreen.style.left)
        // console.log(player.x)

    
        this.ctx.fillStyle = "green";
        var playerObj= {}
        // playerObj[playerName] = {x:player.getX(),y:player.getY(),r:player.angle,idle:0,color:player.color}
        // socket.sendPlayer(JSON.stringify(playerObj))
        // console.log(r)
        this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height)
        
        this.player.render();
        // this.player.status();
        // if(jQuery.isEmptyObject(players)===false){
        //     // console.log(players)
        //     Object.values(players).forEach((player)=>{
        //             createSquare(player);
        //     })  
        // }
        
        // if(jQuery.isEmptyObject(bullets)===false){
        //     Object.values(bullets).forEach((bullet)=>{
        //             drawBullet(bullet);
        //             // if(bullet[1].status()) {
        //             // // delete bullets[bullet[0]]
        //             // }
        //     })
        // checkPlayer(player)
        // nameFollow(player)
        requestAnimationFrame(this.draw) 
}

        }
        
        //where we draw
        // context.drawImage(bgImage, 0,0);
        // context.drawImage(theHero, theHeroLoc.x, theHeroLoc.y);
        // bullet.x++
        
window.onload = ()=>{

    let currentGame = new Game();

    currentGame.start()

}
