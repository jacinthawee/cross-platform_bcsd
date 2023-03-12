
EVP_CIPHER * ENGINE_get_cipher(ENGINE *e,int nid)

{
  int iVar1;
  EVP_CIPHER *local_c;
  
  if ((*(code **)(e + 0x24) != (code *)0x0) &&
     (iVar1 = (**(code **)(e + 0x24))(e,&local_c,0,nid), iVar1 != 0)) {
    return local_c;
  }
  ERR_put_error(0x26,0xb9,0x92,"tb_cipher.c",0x7e);
  return (EVP_CIPHER *)0x0;
}

