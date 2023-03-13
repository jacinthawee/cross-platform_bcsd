
int X509_EXTENSION_set_data(X509_EXTENSION *ex,ASN1_OCTET_STRING *data)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (ex != (X509_EXTENSION *)0x0) {
    iVar2 = ASN1_STRING_set(ex->value,data->data,data->length);
    uVar1 = (uint)(iVar2 != 0);
  }
  return uVar1;
}

