
int EVP_PKEY_get_default_digest_nid(EVP_PKEY *pkey,int *pnid)

{
  code *pcVar1;
  int iVar2;
  
  if ((pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) ||
     (pcVar1 = *(code **)(pkey->ameth + 0x58), pcVar1 == (code *)0x0)) {
    iVar2 = -2;
  }
  else {
    iVar2 = (*pcVar1)(pkey,3,0,pnid);
  }
  return iVar2;
}

