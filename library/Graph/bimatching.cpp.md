---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: Graph/bimatching.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/bimatching.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 00:18:07+09:00




## Depends on

* :warning: <a href="dinic.cpp.html">Graph/dinic.cpp</a>


## Verified with

* :warning: <a href="../../verify/Verify/bimatching.test.cpp.html">Verify/bimatching.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef __guard__
#define __guard__
#include "dinic.cpp"
#undef __guard__
#endif

struct BiMatching {
    MaxFlow<int, true> mf;
    int n, m, s, g;

    explicit BiMatching(int n, int m)
        : mf(n + m + 2), n(n), m(m), s(n + m), g(n + m + 1) {
        for (int u = 0; u < n; ++u) {
            mf.span(s, enc(u, false), 1);
        }
        for (int v = 0; v < m; ++v) {
            mf.span(enc(v, true), g, 1);
        }
    }

    int enc(int v, bool side) {
        return v + (side ? n : 0);
    }

    void span(int u, int v) {
        mf.span(enc(u, false), enc(v, true), 1);
    }

    int exec() {
        return mf.exec(s, g);
    }

    std::vector<std::pair<int, int>> matching() {
        mf.exec(s, g);
        std::vector<std::pair<int, int>> ret;
        for (auto e : mf.edges) {
            if (e.src < e.dst &&
                e.src < n && e.dst < n + m &&
                e.cap == 0) {
                ret.emplace_back(e.src, e.dst - n);
            }
        }
        return ret;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 169, in main
    subcommand_run(paths=[], jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 66, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 68, in main
    exec_command(['oj', 'download', '--system', '-d', shlex.quote(str(directory / 'test')), url])
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 26, in exec_command
    subprocess.check_call(command)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/subprocess.py", line 364, in check_call
    raise CalledProcessError(retcode, cmd)
subprocess.CalledProcessError: Command '['oj', 'download', '--system', '-d', '.verify-helper/cache/de2a20b2f4f2e91bd80377115ed6307e/test', 'https://judge.yosupo.jp/problem/bipartitematching']' returned non-zero exit status 1.

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 328, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: Graph/bimatching.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

