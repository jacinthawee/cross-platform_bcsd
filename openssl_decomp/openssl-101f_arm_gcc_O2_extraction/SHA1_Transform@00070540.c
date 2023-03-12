
void SHA1_Transform(SHA_CTX *c,uchar *data)

{
  __sha1_block_data_order_from_thumb(c,data,1);
  return;
}

