
void X509_trust_clear(X509 *x)

{
  _STACK *st;
  
  if ((*(_STACK ***)(x->sha1_hash + 0xc) != (_STACK **)0x0) &&
     (st = **(_STACK ***)(x->sha1_hash + 0xc), st != (_STACK *)0x0)) {
    sk_pop_free(st,ASN1_OBJECT_free);
    **(undefined4 **)(x->sha1_hash + 0xc) = 0;
  }
  return;
}

