let canvas;
let ctx;

function Game(){
    this.player = null;
    this.mouse = {onCanvas:false, position: {x: -1, y: -1}}
    this.bullets = [];
    this.enemies = []

    this.newContainer = ()=>{
        document.body.innerHTML = "<canvas id=\"view\" style=\" background: #eeeeee;display:flex; justify-content:center; \"><canvas>"
        
    }
    this.checkBulletHitBoxes = ()=>{
        if(this.enemies.length>0&&this.bullets.length>0){
            for(let i = 0; i<this.bullets.length; i++){
                let currentBullet = this.bullets[i]
                for(let j = 0; j<this.enemies.length; j++){
                    let currentEnemy = this.enemies[j];
                    let distanceX = Math.pow(currentEnemy.x
                        -currentBullet.x,2)
                    let distanceY = Math.pow(currentEnemy.y
                        -currentBullet.y,2)
                    let distance = Math.sqrt(distanceX+distanceY)
                    if(distance<currentEnemy.size){
                        console.log('hit')
                        this.bullets.splice(i,1)
                        this.enemies.splice(j,1)
                    };
                }
            }
        }
    }
    this.start = ()=>{
        
        let domSize = screen.width
        console.log(domSize);
        this.newContainer()
        canvas = document.getElementById('view');
        ctx = canvas.getContext('2d');
        canvas.width =  750;
        canvas.height =  750;
        this.player =  new Player(ctx, canvas, this.mouse,"orange");
        this.player.create(0, 0, 10)
        this.enemies.push(new fastCircleEnemy(350,350))
        this.draw()
       
    }

   this.draw = ()=>{
        // console.log(Math.atan(3/2)* 180/Math.PI)
        window.scrollTo(this.player.x- $(window).width()/2+100,this.player.y- $(window).height()/2+100)
        // console.log(theScreen.style.left)
        // console.log(player.x)

    
      
        ctx.clearRect(0, 0, canvas.width, canvas.height)
        this.enemies.forEach(enemy => {
            enemy.render()
            enemy.move()
            enemy.parallaxFunc();
        });
        this.bullets = this.player.render();
        this.checkBulletHitBoxes()
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
