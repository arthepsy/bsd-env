--- src/s6-rc/s6-rc-init.c	2016-04-09 14:57:06.312860000 +0300
+++ src/s6-rc/s6-rc-init.c	2016-04-09 14:57:24.225903000 +0300
@@ -99,8 +99,10 @@
     lfn[llen] = 0 ;
     if (symlink(satmp.s + dirlen, lfn) < 0)
     {
+      char tmp[satmp.len - dirlen] ;
+      byte_copy(tmp, satmp.len - dirlen, satmp.s + dirlen) ;
       cleanup() ;
-      strerr_diefu4sys(111, "symlink ", satmp.s + dirlen, " to ", lfn) ;
+      strerr_diefu4sys(111, "symlink ", tmp, " to ", lfn) ;
     }
     
 
