
void X509_reject_clear(X509 *x)

{
  _STACK *st;
  
  if ((*(int *)(x->sha1_hash + 0xc) != 0) &&
     (st = *(_STACK **)(*(int *)(x->sha1_hash + 0xc) + 4), st != (_STACK *)0x0)) {
    sk_pop_free(st,ASN1_OBJECT_free + 1);
    *(undefined4 *)(*(int *)(x->sha1_hash + 0xc) + 4) = 0;
  }
  return;
}

