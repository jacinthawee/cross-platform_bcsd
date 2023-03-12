
int NETSCAPE_SPKI_verify(NETSCAPE_SPKI *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_verify_006a8d20)
                    (PTR_NETSCAPE_SPKAC_it_006a8f88,a->sig_algor,a->signature,a->spkac,r);
  return iVar1;
}

