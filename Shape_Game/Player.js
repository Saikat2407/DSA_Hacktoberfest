function Player(ctx, canvas, mouse, color)  {
    this.x = 250;
    this.y = 250;
    this.clientX = 0;
    this.clientY = 0;
    this.angle = 0;
    this.speed = 0;
    this.maxSpeed = 5;
    this.bulletSpeed = 15;
    this.bulletArray = []
    this.maxBulletDistance = 500;
    this.color = color;
    this.size;

    this.ctx = ctx
    this.canvas = canvas
    this.mouse = mouse 
    this.keystate={w:false, a:false, s:false, d:false};
    
    this.outOfBoundsCheck = ()=>{
        this.x = this.x + this.size > this.canvas.width ? this.canvas.width - this.size : this.x;
        this.y = this.y + this.size > this.canvas.height ? this.canvas.height - this.size: this.y;
        this.x = this.x - this.size/2 < 0 ? this.size/2: this.x;
        this.y = this.y - this.size/2 < 0 ? this.size/2: this.y;
    }
    this.vectorPhysics = ()=>{
         if(this.keystate.w === true){
            this.speed <=this.maxSpeed ? this.speed +=0.1 : this.speed = this.maxSpeed;
         }else if(this.keystate.w === false){
            this.speed > 0 ? this.speed -= 0.1: this.speed = 0;
         }
         if(this.speed > 0 ){
            this.x -=  this.speed/2 * Math.cos(this.angle+Math.PI/2)
            this.y -=  this.speed/2 * Math.sin(this.angle+Math.PI/2)
            // console.log(this.speed)
         }
    }
    this.createBullet =  ()=>{
        this.bulletArray.push({x:this.x, y:this.y+(10/3), angle:this.angle, distanceTraveled: 0})
    }
    this.addKeyControls = ()=>{
        
            addEventListener('keydown', (e)=>{
                
                if(e.keyCode===40||e.code==='KeyS'){
                    console.log("Guy go backwards")
                    // this.x +=  this.speed/2 * Math.cos(this.angle+Math.PI/2)
                    // this.y +=  this.speed/2 * Math.sin(this.angle+Math.PI/2)
                }else if(e.keyCode===38||e.code==='KeyW'){
                    console.log("Guy go fowards") 
                    // this.x -=  this.speed/2 * Math.cos(this.angle+Math.PI/2)
                    // this.y -=  this.speed/2 * Math.sin(this.angle+Math.PI/2)
                    this.keystate.w = true
                }//if(e.keyCode===37||e.code==='KeyA'){
                //     this.x +=  this.speed * Math.cos(this.angle)
                //     this.y +=  this.speed * Math.sin(this.angle)
                // }else if(e.keyCode===39||e.code==='KeyD'){
                //     this.x -=  this.speed * Math.cos(this.angle)
                //     this.y -=  this.speed * Math.sin(this.angle)
                //}
                // this.vectorPhysics()
            })
            
            addEventListener('keyup', (e)=>{
                //console.log(e.keyCode)
                if(e.code==='KeyW'){//UP
                    this.keystate.w = false

                }
                if(e.keyCode===40){//DOWN
                }
                // if(e.keyCode===39){//Right
                //     diamond.x += 50
                // }
                // if(e.keyCode===37){//Left
                //     diamond.x -= 50
                // }
                    // this.vectorPhysics()
            })
            addEventListener('mousedown', (e)=>{
                this.createBullet()
            })
    }

        this.updateAngle =  ()=>{
            let distanceX = (this.mouse.position.x)-(this.x)
            let distanceY = ((this.mouse.position.y)-(this.y+ 10/3))
            
            this.angle = (Math.atan2(distanceY,distanceX)) - 3 *Math.PI/2
        }

        this.addMouseControls = ()=>{
            var mouse = (e)=> {
                this.mouse.position = {x:e.offsetX, y:e.offsetY}

                var fakex = (window.Event) ? e.pageX : event.clientX + (document.documentElement.scrollLeft ? document.documentElement.scrollLeft : document.body.scrollLeft);
                this.updateAngle()
                let {clientX, layerX, pageX, x, clientY} = e
      
                // console.log(e, this.mouse.position.x, this.mouse.position.y)
                // console.log((player.angle *180/Math.PI)-360)
            }
            canvas.onmousemove = mouse
        }

        this.getRndColor = ()=>{
            var colorPossible = 'abcdefABCDEF1234567890'
            var colorString = '#'
            for(var i = 0; i < 6; i++){
                colorString += colorPossible[Math.floor(Math.random()*22)]
            }
            return colorString;
        }

        this.create =(x, y, size, color)=>{
            this.x = x
            this.y = y
            this.size = size;
            // this.speed = 20;
  
            this.addKeyControls();
            this.addMouseControls();
            //ctx.stroke()
        }

        this.rotateFunc = ([x,y])=>{
            // x-= this.size
            // y-= this.size
            //  return [(x * Math.cos(this.angle)) - (y * Math.sin(this.angle)) , (x * Math.sin(this.angle)) + (y * Math.cos(this.angle))];
            return
        }
        this.addCanvasBoundaries = ([x, y])=>{
            let {left, top} = this.canvas.getBoundingClientRect()
            return [x-left, y-top]
        }

        this.renderBullet = ()=>{
            for(let i = 0; i < this.bulletArray.length; i++){
                let bullet = this.bulletArray[i];
                this.ctx.beginPath()
                this.ctx.arc(bullet.x, bullet.y, 2, 0, Math.PI * 2, true);
                this.ctx.fillStyle = "black"
                this.ctx.fill()
                this.ctx.closePath()
                bullet.x -= this.bulletSpeed * Math.cos(bullet.angle+Math.PI/2)
                bullet.y -=  this.bulletSpeed * Math.sin(bullet.angle+Math.PI/2)
                bullet.distanceTraveled += this.bulletSpeed
                if(bullet.distanceTraveled > this.maxBulletDistance){
                    this.bulletArray.splice(i,1)
                }
            }
        }

        this.render = ()=>{
            
            let tempPoints = [[0, -this.size], [-this.size, this.size], [this.size, this.size]]
        
            const triangle = new Path2D();

            this.updateAngle()
            this.ctx.save();
            this.ctx.beginPath();
            
            // triangle
            this.ctx.translate(this.x,this.y+this.size/3);
            this.ctx.rotate(this.angle)
            this.ctx.translate(-(this.x),-(this.y+this.size/3));
            this.ctx.moveTo(this.x + tempPoints[0][0], this.y+tempPoints[0][1]); //x,y values to start at
            this.ctx.lineTo(this.x+tempPoints[1][0], this.y+tempPoints[1][1]); //draws a line
            this.ctx.lineTo(this.x+tempPoints[2][0], this.y+tempPoints[2][1]); 
            // this.ctx.lineTo(this.x + tempPoints[0][0], this.y+tempPoints[0][1]+this.size/3); //x,y values to start at
            this.ctx.fillStyle = this.color
            this.ctx.fill()
            this.ctx.closePath();
            
            // visble vectors
            this.ctx.beginPath();
            this.ctx.moveTo(this.x, this.y+10/3)
            this.ctx.lineTo(this.x, this.y)
            this.ctx.moveTo(this.x, this.y+10/3)
            this.ctx.lineTo(this.x+10/3, this.y+10/3)
            // this.ctx.arc(this.x - 0.5, this.y+ 3.5, 0.5, 0 ,2 *Math.PI,0)
            this.ctx.lineWidth =  1;
            this.ctx.stroke()
            this.ctx.closePath()
            this.ctx.rotate(-this.angle)
            this.ctx.closePath()
            this.ctx.restore();
            
            // temp mouse circle
            this.ctx.beginPath()
            this.ctx.arc(this.mouse.position.x, this.mouse.position.y, 5, 0, Math.PI * 2, true)
            this.ctx.stroke();
            this.ctx.restore()
            this.outOfBoundsCheck()
            this.vectorPhysics()
            this.renderBullet()
            return this.bulletArray
            // console.log(console.log(Math))
        } 
    }