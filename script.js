// ─── CUSTOM CURSOR ───────────────────────────────────────────────────────────
const dot  = document.getElementById('dot');
const ring = document.getElementById('ring');

// Disable custom cursor on touch devices
const isTouchDevice = () => {
  return (('ontouchstart' in window) || (navigator.maxTouchPoints > 0) || (navigator.msMaxTouchPoints > 0));
};

if (!isTouchDevice()) {
  let mx = 0, my = 0, rx = 0, ry = 0;

  document.addEventListener('mousemove', e => {
    mx = e.clientX;
    my = e.clientY;
    dot.style.left = mx + 'px';
    dot.style.top  = my + 'px';
  });

  (function tick() {
    rx += (mx - rx) * 0.1;
    ry += (my - ry) * 0.1;
    ring.style.left = rx + 'px';
    ring.style.top  = ry + 'px';
    requestAnimationFrame(tick);
  })();
} else {
  // Hide custom cursor on touch devices
  dot.style.display = 'none';
  ring.style.display = 'none';
}

document.querySelectorAll('a, button, .proj-glass, .stat-glass, .cl-item').forEach(el => {
  if (!isTouchDevice()) {
    el.addEventListener('mouseenter', () => {
      dot.style.width  = '4px';
      dot.style.height = '4px';
      ring.style.width  = '48px';
      ring.style.height = '48px';
      ring.style.borderColor = 'rgba(236,72,153,0.5)';
    });
    el.addEventListener('mouseleave', () => {
      dot.style.width  = '6px';
      dot.style.height = '6px';
      ring.style.width  = '32px';
      ring.style.height = '32px';
      ring.style.borderColor = 'rgba(167,139,250,0.5)';
    });
  }
});

// ─── SCROLL REVEAL ────────────────────────────────────────────────────────────
const io = new IntersectionObserver(entries => {
  entries.forEach((e, i) => {
    if (e.isIntersecting) {
      setTimeout(() => e.target.classList.add('on'), i * 80);
    }
  });
}, { threshold: 0.07 });

document.querySelectorAll('.reveal').forEach(el => io.observe(el));

// ─── ACTIVE NAV HIGHLIGHT ────────────────────────────────────────────────────
window.addEventListener('scroll', () => {
  let current = '';

  document.querySelectorAll('section').forEach(s => {
    if (window.scrollY >= s.offsetTop - 240) current = s.id;
  });

  document.querySelectorAll('.nav-list a').forEach(a => {
    const isActive = a.getAttribute('href') === '#' + current;
    a.style.color      = isActive ? '#a78bfa' : '';
    a.style.background = isActive ? 'rgba(139,92,246,0.12)' : '';
  });
});


