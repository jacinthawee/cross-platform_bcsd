
int OCSP_request_add1_nonce(OCSP_REQUEST *req,uchar *val,int len)

{
  int iVar1;
  OCSP_REQINFO *pOVar2;
  uchar *local_24;
  int local_20 [2];
  uchar *local_18;
  
  if (len < 1) {
    len = 0x10;
  }
  pOVar2 = req->tbsRequest;
  local_20[0] = ASN1_object_size(0,len,4);
  local_24 = (uchar *)CRYPTO_malloc(local_20[0],"ocsp_ext.c",0x165);
  if (local_24 == (uchar *)0x0) {
    return 0;
  }
  local_18 = local_24;
  ASN1_put_object(&local_24,0,len,4,0);
  if (val == (uchar *)0x0) {
    iVar1 = RAND_bytes(local_24,len);
    if (iVar1 < 1) goto LAB_000df510;
  }
  else {
    memcpy(local_24,val,len);
  }
  val = (uchar *)X509V3_add1_i2d(&pOVar2->requestExtensions,0x16e,local_20,0,2);
  if (val != (uchar *)0x0) {
    val = (uchar *)0x1;
  }
LAB_000df510:
  if (local_18 != (uchar *)0x0) {
    CRYPTO_free(local_18);
  }
  return (int)val;
}

