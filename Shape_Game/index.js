let canvas;
let ctx;

function Game(){
    this.player = null;
    this.mouse = {onCanvas:false, position: {x: -1, y: -1}}
    this.bullets = [];
    this.enemies = [];
    this.levelPlaying = false;
    this.currentLevel = 0;
    this.newContainer = ()=>{
        document.body.innerHTML = `<canvas id=\"view\" style=\" background: #eeeeee;display:flex; justify-content:center; \"></canvas>
        <h1 style=\"display:flex; position:absolute; top: 20px; left: 50%; align-items: center; justify-content: center;\" id=\"LevelTitle\"></h1>
        `
        
    }
    this.nextLevel = ()=>{
        if(this.currentLevel){
            for(let i = 0; i< this.currentLevel % 10; i++){
                this.enemies.push(new Enemy(regularEnemy))
            }
            for(let i = 0; i< this.currentLevel % 100; i+=10){
                this.enemies.push(new Enemy(fastCircleEnemy))
            }

        }
        
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
                        // console.log('hit')
                        
                        this.bullets.splice(i,1)
                        this.enemies.splice(j,1)
                        if(this.enemies.length === 0)this.levelPlaying = false
                    };
                }
            }
        }
    }
    this.checkEnemyAndPlayerColision = ()=>{
        if(this.enemies.length > 1){
            const enemiesTempArray = Array.from(this.enemies)
            let currentIndex = 0;
            while(enemiesTempArray.length>1){
                let firstEnemy =  enemiesTempArray.shift();
                let secondEnemy;
                for(let i = 0; i < enemiesTempArray.length; i++){
                    secondEnemy = enemiesTempArray[i]
                    let distanceX = Math.pow(secondEnemy.x
                        -firstEnemy.x,2)
                    let distanceY = Math.pow(secondEnemy.y
                        -firstEnemy.y,2)
                    let distance = Math.sqrt(distanceX+distanceY)
                    let bigSize = secondEnemy.size > firstEnemy.size? secondEnemy.size : firstEnemy.size
                    if(distance<bigSize){
                        // need to work on collision physics.
                        console.log('we collided')
                        let angleOfCollision = Math.acos(Math.atan(secondEnemy.angle)/(2*Math.atan(firstEnemy.angle)))
                        // console.log(angleOfCollision, console.log(this.enemies))
                        this.enemies[currentIndex].angle += Math.PI/2
                        this.enemies[currentIndex+i].angle -= Math.PI/2
                        // this.enemies.splice(currentIndex,1)
                        // this.enemies.splice(currentIndex+i,1)
                    };
                }
                currentIndex++
            }
        }
    }

    this.start = ()=>{
        
        let domSize = screen.width
        console.log(domSize);
        this.newContainer()
        canvas = document.getElementById('view');
        title = document.getElementById('LevelTitle')
        ctx = canvas.getContext('2d');
        canvas.width =  750;
        canvas.height =  750;
        this.player =  new Player(ctx, canvas, this.mouse,"orange");
        this.player.create(375, 375, 10)
        this.draw()
       
    }

   this.draw = ()=>{
        // console.log(Math.atan(3/2)* 180/Math.PI)
        window.scrollTo(this.player.x- $(window).width()/2+100,this.player.y- $(window).height()/2+100)
        // console.log(theScreen.style.left)
        // console.log(player.x)
        if(this.levelPlaying == false){
            this.currentLevel+= 1
            title.innerHTML = `Level: ${this.currentLevel}`

            this.levelPlaying = true
            console.log(console.log(this.currentLevel))
            this.nextLevel()
        }
    
      
        ctx.clearRect(0, 0, canvas.width, canvas.height)
        this.enemies.forEach(enemy => {
            enemy.render()
            enemy.move()
            enemy.parallaxFunc();
        });
        this.bullets = this.player.render();
        this.checkBulletHitBoxes()
        this.checkEnemyAndPlayerColision()

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
