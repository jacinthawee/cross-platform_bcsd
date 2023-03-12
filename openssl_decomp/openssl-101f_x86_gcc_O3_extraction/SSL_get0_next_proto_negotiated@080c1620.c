
void SSL_get0_next_proto_negotiated(SSL *s,uchar **data,uint *len)

{
  SSL_CTX *pSVar1;
  
  pSVar1 = s->initial_ctx;
  *data = (uchar *)pSVar1;
  if (pSVar1 != (SSL_CTX *)0x0) {
    *len = (uint)*(byte *)&s->next_proto_negotiated;
    return;
  }
  *len = 0;
  return;
}

