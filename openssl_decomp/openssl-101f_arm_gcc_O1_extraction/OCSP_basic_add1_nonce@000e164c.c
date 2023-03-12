
int OCSP_basic_add1_nonce(OCSP_BASICRESP *resp,uchar *val,int len)

{
  int iVar1;
  OCSP_RESPDATA *pOVar2;
  uchar *local_24;
  int local_20 [2];
  uchar *local_18;
  
  if (len < 1) {
    len = 0x10;
  }
  pOVar2 = resp->tbsResponseData;
  local_20[0] = ASN1_object_size(0,len,4);
  local_24 = (uchar *)CRYPTO_malloc(local_20[0],"ocsp_ext.c",0x14a);
  if (local_24 != (uchar *)0x0) {
    local_18 = local_24;
    ASN1_put_object(&local_24,0,len,4,0);
    if (val == (uchar *)0x0) {
      RAND_pseudo_bytes(local_24,len);
    }
    else {
      memcpy(local_24,val,len);
    }
    iVar1 = X509V3_add1_i2d(&pOVar2->responseExtensions,0x16e,local_20,0,2);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    if (local_18 != (uchar *)0x0) {
      CRYPTO_free(local_18);
    }
    return iVar1;
  }
  return 0;
}

