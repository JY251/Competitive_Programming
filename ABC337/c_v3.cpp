#include <iostream>

template <typename T>
struct Node {
	T data;
	Node* prev;
	Node* next;

	Node(const T& value): data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class MultiSegmentArray {
	private:
		Node<T>* StartNode;

	public:
		MultiSegmentArray(): startNode(nullptr) {}

		void addToStart(const T& value) {
			Node<T>* newNode = new Node<T>(value);
			newNode->next = startNode;
			// if start node is null (i.e., nothing in the list), then just replace start node with new node
			if (startNode != nullptr) {
				startNode->prev = newNode;
			}
			startNode = newNode;
		}

		void addToEnd(const T& value) {
			Node<T>* newNode = new Node<T>(value);
			if (startNode == nullptr) {
				// if start node is null (i.e., nothing in the list), then just replace start node with new node
				startNode = newNode;
			} else {
				Node<T>* lastNode = startNode;
				while (lastNode->next != nullptr) {
					lastNode = lastNode->next;
				}
				lastNode->next = newNode;
				newNode->prev = lastNode;
			}

			void concatenate(MultiSegmentArray<T>& otherArray) {
				if (startNode == nullptr) {
					startNode = otherArray.startNode;
				} else if (otherArray.startNode != nullptr) {
					Node<T>* lastNode = startNode;
					while (lastNode->next != nullptr) {
						lastNode = lastNode->next;
					}
					lastNode->next = otherArray.startNode;
					otherArray.startNode->prev = lastNode;
				}
			}
		}
}

int main() {
	int N;
	cin >> N;

	vector<int> A(N);

	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	vector<int> order(N, 0);

	for (int i = 0; i < N; ++i) {
		if (A[i] == -1) {
			order[0] = i + 1;
			break;
		}
	}

	for (int i = 0; i < N; ++i) {
		MultiSegmentArray<int> order;
		order.addToEnd(i);
		order.addToStart(A[i]);
	}



}