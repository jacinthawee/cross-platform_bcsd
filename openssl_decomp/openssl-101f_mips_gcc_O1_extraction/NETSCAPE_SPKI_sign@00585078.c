
int NETSCAPE_SPKI_sign(NETSCAPE_SPKI *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_sign_006aa0a4)
                    (PTR_NETSCAPE_SPKAC_it_006aa0a0,x->sig_algor,0,x->signature,x->spkac,pkey,md);
  return iVar1;
}

