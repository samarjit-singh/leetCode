/**
 * @param {number[]} dist
 * @param {number[]} speed
 * @return {number}
 */
var eliminateMaximum = function(dist, speed) {
    var time = [];
    
    for(var i =0;i<dist.length;i++){
        if(dist[i]%speed[i] === 0){
            time.push(dist[i]/speed[i]);
        } else {
            time.push(Math.floor(dist[i]/speed[i])+1);
        }
    }
    
    time.sort((a,b) => a-b);
    
    var monster = 0;
    
    for (var i = 0; i < time.length; i++) {
        if (time[i] - monster <= 0) {
            return i; // able to kill only these many monsters
        } else {
            monster++;
        }
    }
    
    return monster;
    
};