var input = require('fs').readFileSync('/dev/stdin', 'utf8');
var a = input.split(' ').map(v => parseInt(v));
var n = a[0];
var x = a[1] - 1;
var y = a[2] - 1;

var ans = Array(n).fill(0);
for (var i = 0; i < n; i++) {
  var q = [];
  var d = [];
  var push = (k, dist) => {
    if (d[k]) return;
    d[k] = dist;
    if (dist) ans[dist] = 1 + ans[dist] || 0;
    q.push(k);
  }
  push(i, 0);
  while (q.length > 0) {
    var j = q.shift();
    if (j - 1 >= 0) push(j - 1, d[j] + 1);
    if (j + 1 < n) push(j + 1, d[j] + 1);
    if (j === x) push(y, d[j] + 1);
    if (j === y) push(x, d[j] + 1);
  }
  for (var j = 0; j < n; j++) ans[d[i]]++;
}
for (var i = 0; i < n; i++) {
  console.log(ans[i] / 2);
}