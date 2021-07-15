// Entry files
import * as UE from 'ue'

// 静态wrap

console.log('----------------------------------------------------')
const vec = new UE.Vector(1, 2, 3)
console.log('vec', vec.ToString())
vec.X = 3
vec.Y = 2
vec.Z = 1
vec.Normalize(1)
console.log('vec', vec.ToString())
console.log(vec.Projection().ToString())
console.log('vec', vec.ToString())
