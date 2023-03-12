
void SHA256_Transform(SHA256_CTX *c,uchar *data)

{
  __sha256_block_data_order_from_thumb(c,data,1);
  return;
}

