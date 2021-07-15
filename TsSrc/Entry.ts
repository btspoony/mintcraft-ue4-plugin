// Entry files
// import * as UE from 'ue'
import { on } from 'puerts'

// unhandledRejection
on('unhandledRejection', function (reason: any) {
  console.log('unhandledRejection:', reason.stack)
})
