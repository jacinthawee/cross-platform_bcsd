
int BIO_ssl_copy_session_id(BIO *to,BIO *from)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_BIO_find_type_006a943c)(to,0x207);
  iVar2 = (*(code *)PTR_BIO_find_type_006a943c)(from,0x207);
  if ((((iVar1 != 0) && (iVar2 != 0)) && (**(SSL ***)(iVar1 + 0x20) != (SSL *)0x0)) &&
     (**(SSL ***)(iVar2 + 0x20) != (SSL *)0x0)) {
    SSL_copy_session_id(**(SSL ***)(iVar1 + 0x20),**(SSL ***)(iVar2 + 0x20));
    return 1;
  }
  return 0;
}

