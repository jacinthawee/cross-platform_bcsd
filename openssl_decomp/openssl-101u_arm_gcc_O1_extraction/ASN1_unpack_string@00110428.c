
void * ASN1_unpack_string(ASN1_STRING *oct,undefined1 *d2i)

{
  void *pvVar1;
  uchar *local_14 [2];
  
  local_14[0] = oct->data;
  pvVar1 = (void *)(*(code *)d2i)(0,local_14,oct->length);
  if (pvVar1 != (void *)0x0) {
    return pvVar1;
  }
  ERR_put_error(0xd,0x88,0x6e,"asn_pack.c",0x79);
  return (void *)0x0;
}

