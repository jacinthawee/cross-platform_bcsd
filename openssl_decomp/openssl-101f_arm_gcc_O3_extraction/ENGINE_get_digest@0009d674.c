
EVP_MD * ENGINE_get_digest(ENGINE *e,int nid)

{
  int iVar1;
  EVP_MD *local_c;
  
  if ((*(code **)(e + 0x28) != (code *)0x0) &&
     (iVar1 = (**(code **)(e + 0x28))(e,&local_c,0,nid), iVar1 != 0)) {
    return local_c;
  }
  ERR_put_error(0x26,0xba,0x93,"tb_digest.c",0x7e);
  return (EVP_MD *)0x0;
}

