
int EVP_MD_size(EVP_MD *md)

{
  if (md != (EVP_MD *)0x0) {
    return md->md_size;
  }
  ERR_put_error(6,0xa2,0x9f,"evp_lib.c",0x122);
  return -1;
}

