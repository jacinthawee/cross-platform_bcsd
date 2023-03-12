
int NETSCAPE_SPKI_sign(NETSCAPE_SPKI *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_sign_006a8f8c)
                    (PTR_NETSCAPE_SPKAC_it_006a8f88,x->sig_algor,0,x->signature,x->spkac,pkey,md);
  return iVar1;
}

