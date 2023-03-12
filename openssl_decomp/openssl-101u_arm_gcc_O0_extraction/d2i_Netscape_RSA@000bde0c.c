
RSA * d2i_Netscape_RSA(RSA **a,uchar **pp,long length,cb *cb)

{
  RSA *val;
  RSA *pRVar1;
  int iVar2;
  cb *pcVar3;
  uchar *local_1c;
  
  local_1c = *pp;
  val = (RSA *)ASN1_item_d2i((ASN1_VALUE **)0x0,&local_1c,length,
                             (ASN1_ITEM *)PTR_NETSCAPE_ENCRYPTED_PKEY_it_000bdeec);
  if (val == (RSA *)0x0) {
    ERR_put_error(0xd,200,0x6f,"n_pkey.c",0xfb);
  }
  else {
    if ((*(int *)val->pad != 0xb) ||
       (pRVar1 = (RSA *)strncmp("private-key",(char *)((int *)val->pad)[2],0xb),
       pRVar1 != (RSA *)0x0)) {
      ERR_put_error(0xd,200,0x92,"n_pkey.c",0x102);
      ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_NETSCAPE_ENCRYPTED_PKEY_it_000bdeec);
      return (RSA *)0x0;
    }
    iVar2 = OBJ_obj2nid(**(ASN1_OBJECT ***)val->version);
    if (iVar2 == 5) {
      pcVar3 = EVP_read_pw_string + 1;
      if (cb != (cb *)0x0) {
        pcVar3 = cb;
      }
      iVar2 = *(int *)(val->version + 4);
      pRVar1 = (RSA *)d2i_RSA_NET_2_isra_0(a,iVar2,iVar2 + 8,pcVar3,0);
      if (pRVar1 != (RSA *)0x0) {
        *pp = local_1c;
      }
    }
    else {
      ERR_put_error(0xd,200,0xa6,"n_pkey.c",0x107);
    }
    ASN1_item_free((ASN1_VALUE *)val,(ASN1_ITEM *)PTR_NETSCAPE_ENCRYPTED_PKEY_it_000bdeec);
    val = pRVar1;
  }
  return val;
}

