source: http://atc001.contest.atcoder.jp/submissions/862212

class Disjoint {
public:
	vi rank, p;
	Disjoint(){}
	Disjoint(int n) {
		rank.resize(n);
		p.resize(n);
		REP(i, n) {
			p[i] = i;
		}
	}

	int root(int x) {
		if (p[x] == x) {
			return x;
		} else {
			return p[x] = root(p[x]);
		}
	}

	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return;

		if (rank[x] < rank[y]) {
			p[x] = y;
		} else {
			p[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y) {
		return root(x) == root(y);
	}
};
