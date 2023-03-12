
int BIO_sock_error(int sock)

{
  int iVar1;
  int iStack_10;
  socklen_t local_c;
  
  local_c = 4;
  iVar1 = getsockopt(sock,1,4,&iStack_10,&local_c);
  if (iVar1 < 0) {
    iStack_10 = 1;
  }
  return iStack_10;
}

