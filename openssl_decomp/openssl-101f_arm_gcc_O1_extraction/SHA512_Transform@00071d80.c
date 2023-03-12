
void SHA512_Transform(SHA512_CTX *c,uchar *data)

{
  __sha512_block_data_order_from_thumb(c,data,1);
  return;
}

