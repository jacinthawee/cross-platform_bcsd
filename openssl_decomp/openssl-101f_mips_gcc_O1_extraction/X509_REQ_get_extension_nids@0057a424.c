
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int * X509_REQ_get_extension_nids(void)

{
  return (int *)ext_nids;
}

