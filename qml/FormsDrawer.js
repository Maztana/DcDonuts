var size = width/35*2

function drawForms(context, numberForms){
    var rand = Math.round(Math.random()*2);
    switch (rand)
    {
        case 0: drawRounds(context, numberForms);
                break;
        case 1: drawSquares(context, numberForms);
                break;
        case 2: drawTriangles(context, numberForms);
                break;
    }
}

function drawRounds(context, numberForms){

    var diameter = size;

    var list =[];

    for(var i=0; i < numberForms; i++)
    {
        var drawOk = false
        var form={};

        while(!drawOk)
        {
            var x = diameter/2 + Math.random()*(width-diameter)
            var y = diameter/2 + Math.random()*(height-diameter)

            form['x'] = x;
            form['y'] = y;
            form['width'] = diameter
            form['height'] = diameter

            var collision = false

            for(var cpt=0; !collision && cpt<list.length; cpt++)
            {
                collision = isCollisionRound(form, list[cpt]);
            }

            if(!collision)
            {
                drawOk=true;
            }
        }

        list.push(form);

        drawRound(context, form);
    }
}

function drawSquares(context, numberForms){

    var side = size;

    var list =[];

    for(var i=0; i < numberForms; i++)
    {
        var drawOk = false
        var form={};

        while(!drawOk)
        {
            var x = Math.random()*(width-side)
            var y = Math.random()*(height-side)

            form['x'] = x;
            form['y'] = y;
            form['width'] = side
            form['height'] = side

            var collision = false

            for(var cpt=0; !collision && cpt<list.length; cpt++)
            {
                collision = isCollisionSquare(form, list[cpt]);
            }

            if(!collision)
            {
                drawOk=true;
            }
        }

        list.push(form);

        drawSquare(context, form);
    }
}

function drawTriangles(context, numberForms){

    var side = size;

    var list =[];

    for(var i=0; i < numberForms; i++)
    {
        var drawOk = false
        var form={};

        while(!drawOk)
        {
            var h = side*(Math.sqrt(3)/2)
            var x = Math.random()*(width-side)
            var y = h+Math.random()*(height - h)

            form['x'] = x;
            form['y'] = y;
            form['width'] = side
            form['height'] = h

            var collision = false

            for(var cpt=0; !collision && cpt<list.length; cpt++)
            {
                collision = isCollisionSquare(form, list[cpt]);
            }

            if(!collision)
            {
                drawOk=true;
            }
        }

        list.push(form);

        drawTriangle(context, form);
    }
}

function drawRound(context, form){
    var x = form.x
    var y = form.y
    var radius = form.width/2

    context.beginPath();
    context.lineWidth = 2;
    context.arc(x, y, radius, 0, 2*Math.PI, true)
    context.fillStyle = "orange"
    context.fill();
}

function drawSquare(context, form)
{
    var x = form.x
    var y = form.y
    var side = form.width

    context.beginPath();
    context.fillStyle = "blue"
    context.fillRect(x, y, side, side);
    context.fill();
}

function drawTriangle(context, form)
{
    var x = form.x
    var y = form.y
    var side = form.width
    var h = form.height

    context.beginPath();
    context.lineWidth = 2;
    context.fillStyle = "green"
    context.moveTo(x,y)
    context.lineTo(x+side, y)
    context.lineTo(x+(side/2), y-h)
    context.lineTo(x, y)
    context.fill();
}

function isCollisionRound(form, formCompared)
{
    var xForm = form.x-form.width/2
    var yForm = form.y-form.height/2
    var xFormCompared = formCompared.x-formCompared.width/2
    var yFormCompared = formCompared.y-formCompared.height/2

    return isCollision(xForm, yForm, xFormCompared, yFormCompared, form.width, form.height);
}

function isCollisionSquare(form, formCompared)
{
    return isCollision(form.x, form.y, formCompared.x, formCompared.y, form.width, form.height);
}

function isCollision(xForm, yForm, xFormCompared, yFormCompared, width, height)
{
    if((xForm >= xFormCompared + width + 5)
        || (xForm + width + 5<= xFormCompared)
        || (yForm >= yFormCompared + height + 5)
        || (yForm + height + 5 <= yFormCompared))
    {
        return false;
    }
    else
    {
        return true;
    }
}
