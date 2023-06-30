/**
 * @param {number} row
 * @param {number} col
 * @param {number[][]} cells
 * @return {number}
 */
var latestDayToCross = function(row, col, cells) {
    
    
    function util(cells,row,col,dayAt){
        const dx = [0, 0, -1, 1];
        const dy = [-1, 1, 0, 0]; 
        
        const grid = Array(row).fill().map(()=>Array(col).fill(false));
        
        for(let i = 0; i< dayAt; i++){
            grid[cells[i][0] - 1][cells[i][1] - 1] = true;
        }
        
        const queue = [];
        for (let c = 0; c < col; c++) {
          if (!grid[0][c]) {
            queue.push([0, c]);
            grid[0][c] = true;
          }
        }
        
        while (queue.length > 0) {
          const [r, c] = queue.shift();
          if (r === row - 1) {
            return true;
          }
          for (let i = 0; i < 4; i++) {
            const nr = r + dx[i];
            const nc = c + dy[i];
            if (
              nr < 0 ||
              nr === row ||
              nc < 0 ||
              nc === col ||
              grid[nr][nc]
            ) {
              continue;
            }
            grid[nr][nc] = true;
            queue.push([nr, nc]);
          }
        }
        return false;
        
    }
    
    let left = 1;
    let right = cells.length;
    let ans = 0;
    
    while(left<=right){
        const mid = left + Math.floor((right-left)/2);
        if(util(cells,row,col,mid)){
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return ans;
};