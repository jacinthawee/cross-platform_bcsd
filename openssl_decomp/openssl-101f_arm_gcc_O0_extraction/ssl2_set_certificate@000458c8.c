
X509 * ssl2_set_certificate(int param_1,undefined4 param_2,long param_3,uchar *param_4)

{
  X509 *x;
  X509 *st;
  int iVar1;
  X509 *pXVar2;
  X509 *pkey;
  X509 *pXVar3;
  uchar *local_1c;
  
  local_1c = param_4;
  x = d2i_X509((X509 **)0x0,&local_1c,param_3);
  if (x == (X509 *)0x0) {
    ERR_put_error(0x14,0x7e,0xb,"s2_clnt.c",0x40f);
    pXVar3 = x;
    pkey = x;
    st = x;
  }
  else {
    st = (X509 *)sk_new_null();
    if ((st == (X509 *)0x0) || (iVar1 = sk_push((_STACK *)st,x), iVar1 == 0)) {
      ERR_put_error(0x14,0x7e,0x41,"s2_clnt.c",0x415);
      pXVar3 = (X509 *)0x0;
      pkey = (X509 *)0x0;
    }
    else {
      iVar1 = ssl_verify_cert_chain(param_1,st);
      if ((*(int *)(param_1 + 200) == 0) || (0 < iVar1)) {
        ERR_clear_error();
        *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xa0) = *(undefined4 *)(param_1 + 0xec);
        pXVar2 = (X509 *)ssl_sess_cert_new();
        if (pXVar2 == (X509 *)0x0) {
          pXVar3 = (X509 *)0xffffffff;
          pkey = pXVar2;
        }
        else {
          iVar1 = *(int *)(param_1 + 0xc0);
          if (*(int *)(iVar1 + 0x98) != 0) {
            ssl_sess_cert_free();
            iVar1 = *(int *)(param_1 + 0xc0);
          }
          *(X509 **)(iVar1 + 0x98) = pXVar2;
          pXVar2->valid = (int)x;
          pXVar2->signature = (ASN1_BIT_STRING *)&pXVar2->valid;
          pkey = (X509 *)X509_get_pubkey(x);
          if (pkey == (X509 *)0x0) {
            ERR_put_error(0x14,0x7e,0xed,"s2_clnt.c",0x434);
            x = pkey;
            pXVar3 = pkey;
          }
          else if (pkey->cert_info == (X509_CINF *)0x6) {
            pXVar3 = (X509 *)ssl_set_peer_cert_type(pXVar2,1);
            x = (X509 *)0x0;
            if (pXVar3 != (X509 *)0x0) {
              pXVar3 = (X509 *)0x1;
            }
          }
          else {
            ERR_put_error(0x14,0x7e,0xd2,"s2_clnt.c",0x439);
            x = (X509 *)0x0;
            pXVar3 = (X509 *)0x0;
          }
        }
      }
      else {
        ERR_put_error(0x14,0x7e,0x86,"s2_clnt.c",0x41d);
        pXVar3 = (X509 *)0x0;
        pkey = (X509 *)0x0;
      }
    }
  }
  sk_free((_STACK *)st);
  X509_free(x);
  EVP_PKEY_free((EVP_PKEY *)pkey);
  return pXVar3;
}

